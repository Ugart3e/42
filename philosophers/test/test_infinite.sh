#!/bin/bash

CMD="../a.out 5 800 200 200"
$CMD > output.log &

PID=$!
sleep 5

if ps -p $PID > /dev/null; then
    echo "✅ Simulación infinita sigue corriendo"
else
    echo "❌ Simulación terminó inesperadamente"
    tail output.log
    exit 1
fi

if grep -q "died" output.log; then
    echo "❌ Un filósofo murió"
    grep "died" output.log
    kill $PID
    exit 1
else
    echo "✅ Ningún filósofo murió"
fi

kill $PID
wait $PID 2>/dev/null
