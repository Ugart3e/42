#!/bin/bash

CMD="../a.out 7 800 200 200"
$CMD > output.log &

PID=$!
sleep 5

if ps -p $PID > /dev/null; then
    echo "✅ Simulación (7 filósofos) sigue corriendo – sin deadlock"
else
    echo "❌ Deadlock detectado o crash"
    tail output.log
    exit 1
fi

kill $PID
wait $PID 2>/dev/null
