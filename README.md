# Advent 2024 - Mborg BeerSelector

Testproject for the code for the Beer Selector.

## Preparing build

To prepare the `cmake` files, enter the following commands:

```bash
cd build
cmake ..
```

## Building for debugging

To generate debugging files, run the following commands:

```bash
cd build
cmake --build . --target=app_debug
```

## Building for production

To generate release files, run the following commands:

```bash
cd build
cmake --build . --target=app
```