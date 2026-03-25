# Contributing to PerimeterAnimator

Спасибо за интерес к проекту! Этот документ описывает правила внесения изменений.

## Как внести вклад

### Сообщение об ошибках

- Используйте раздел [Issues](../../issues)
- Опишите шаги воспроизведения
- Укажите версию Windows и Visual Studio
- Приложите скриншоты если применимо

### Предложение улучшений

- Создайте Issue с префиксом `[Feature]`
- Опишите желаемое поведение
- Объясните, почему это улучшение полезно

### Pull Requests

1. Fork репозитория
2. Создайте ветку: `git checkout -b feature/my-feature`
3. Commit изменения: `git commit -am 'Add feature'`
4. Push: `git push origin feature/my-feature`
5. Откройте Pull Request

## Стандарты кода

### C++/CLI

- Используйте понятные имена переменных (camelCase)
- Комментарии на русском или английском
- Отступы: табуляция
- Максимальная длина строки: 120 символов

### Пример

```cpp
// Хорошо
int lineLength = Convert::ToInt32(numericUpDown1->Value);

// Плохо
int l = Convert::ToInt32(numericUpDown1->Value);
```

## Лицензия

Внося изменения, вы соглашаетесь с тем, что ваш код будет под лицензией MIT.
