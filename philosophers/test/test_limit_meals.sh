#!/bin/bash

CMD="../a.out 5 800 200 200 3"
$CMD > output.log

if grep -q "ALL PHILOS ARE FULL!" output.log; then
    echo "✅ Simulación terminó cuando todos comieron 3 veces"
else
    echo "❌ La simulación no terminó correctamente"
    tail output.log
    exit 1
fi

if grep -q "died" output.log; then
    echo "❌ Un filósofo murió antes de terminar"
    grep "died" output.log
    exit 1
else
    echo "✅ Ningún filósofo murió antes de llenarse"
fi
