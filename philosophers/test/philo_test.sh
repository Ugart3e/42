#!/bin/bash

PHILO_EXEC=../a.out

# Colores
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

run_test() {
    echo -e "\nTest: $1"
    $PHILO_EXEC $1 > tmp.log &
    PID=$!

    # Espera unos segundos dependiendo del test
    sleep $2
    kill $PID 2>/dev/null

    if grep -q "died" tmp.log; then
        echo -e "${RED}Resultado: Un filósofo murió.${NC}"
    else
        echo -e "${GREEN}Resultado: Nadie murió.${NC}"
    fi

    MEALS=$(grep "is eating" tmp.log | wc -l)
    echo "Veces totales que se comió: $MEALS"

    rm -f tmp.log
}

# Construcción
echo "Compilando el proyecto..."
$MAKECMD >/dev/null || { echo "Error al compilar"; exit 1; }

# Tests requeridos
run_test "1 800 200 200" 2     # Debe morir
run_test "5 800 200 200" 3     # Nadie debe morir
run_test "5 800 200 200 7" 5       # Termina cuando todos han comido 7 veces
run_test "4 410 200 200" 3     # Nadie debe morir
run_test "3 310 200 100" 3     # Alguien debería morir
run_test "2 800 200 200" 3     # Test de sincronización, debería sobrevivir
