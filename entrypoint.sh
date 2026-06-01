#!/bin/sh

echo "Waiting for app pod to be ready..."
while true; do
  APP_POD=$(kubectl get pods -l app=app -o jsonpath='{.items[0].metadata.name}' 2>/dev/null)
  if [ -n "$APP_POD" ]; then
    break
  fi
  sleep 2
done

echo "Fetching logs from pod $APP_POD"
# Ждём, пока логи не появятся
while true; do
  LOGS=$(kubectl logs $APP_POD 2>/dev/null)
  if [ -n "$LOGS" ]; then
    echo "$LOGS" > /usr/share/nginx/html/index.html
    echo "Logs saved successfully"
    break
  fi
  sleep 2
done

nginx -g 'daemon off;'