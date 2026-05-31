FROM gcc:latest

# Устанавливаем зависимости
RUN apt-get update && apt-get install -y \
    cmake \
    libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Копируем файлы проекта
COPY . .

# Создаём папку сборки
RUN mkdir build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    cmake --build . --config Release

# Запускаем тесты
CMD ["./build/testproj"]
