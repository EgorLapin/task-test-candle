#!/bin/bash

echo "Waiting for app container to finish..."
sleep 3  # даём время app контейнеру завершить тесты

# Получаем логи контейнера app (по имени сервиса)
docker logs app > /usr/share/nginx/html/index.html 2>&1 || echo "No logs available" > /usr/share/nginx/html/index.html

# Запускаем nginx
nginx -g 'daemon off;'