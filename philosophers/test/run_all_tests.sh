#!/bin/bash

echo "📦 Ejecutando todos los tests..."
for test in test_*.sh; do
    echo "🧪 $test"
    bash "$test" || exit 1
    echo
done

echo "🎉 Todos los tests pasaron correctamente"
