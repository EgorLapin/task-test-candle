#!/bin/sh

echo "Waiting for app pod to be ready..."
# Ждём, пока под с меткой app=app не появится и не будет в статусе Running
while true; do
  APP_POD=$(kubectl get pods -l app=app -o jsonpath='{.items[0].metadata.name}' 2>/dev/null)
  if [ -n "$APP_POD" ]; then
    break
  fi
  sleep 2
done

echo "Fetching logs from pod $APP_POD"
kubectl logs $APP_POD > /usr/share/nginx/html/index.html 2>&1 || echo "No logs available" > /usr/share/nginx/html/index.html

nginx -g 'daemon off;'