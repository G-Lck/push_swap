#!/bin/bash

# Script de benchmark pour push_swap
# Tests avec différentes tailles et configurations

echo "=== PUSH_SWAP BENCHMARK TESTS ==="
echo "Date: $(date)"
echo

# Fonction pour générer une séquence aléatoire
generate_random() {
    local size=$1
    shuf -i 1-$((size*2)) -n $size | tr '\n' ' ' | sed 's/ $//'
}

# Fonction pour générer une séquence inverse
generate_reverse() {
    local size=$1
    seq $size -1 1 | tr '\n' ' ' | sed 's/ $//'
}

# Fonction pour tester et compter les instructions
test_case() {
    local name="$1"
    local numbers="$2"
    local expected_max="$3"

    echo "Testing: $name"
    echo "Input: $numbers"

    local instructions=$($PUSH_SWAP "$numbers" 2>/dev/null | wc -l)
    local result=$($PUSH_SWAP "$numbers" 2>/dev/null | $CHECKER "$numbers" 2>/dev/null)

    echo "Instructions: $instructions"
    echo "Checker result: $result"

    if [ "$result" = "OK" ]; then
        if [ $instructions -le $expected_max ]; then
            echo "✅ PASS (within limit: $expected_max)"
        else
            echo "⚠️  PASS but over limit (expected ≤$expected_max)"
        fi
    else
        echo "❌ FAIL - sorting incorrect"
    fi
    echo
}

# Fonction pour tests multiples avec moyenne
benchmark_size() {
    local size=$1
    local expected_max=$2
    local num_tests=10
    local total=0
    local passed=0

    echo "=== BENCHMARK: $size elements (limit: $expected_max) ==="

    for i in $(seq 1 $num_tests); do
        local numbers=$(generate_random $size)
        local instructions=$($PUSH_SWAP "$numbers" 2>/dev/null | wc -l)
        local result=$($PUSH_SWAP "$numbers" 2>/dev/null | $CHECKER "$numbers" 2>/dev/null)

        total=$((total + instructions))

        if [ "$result" = "OK" ]; then
            passed=$((passed + 1))
            if [ $instructions -le $expected_max ]; then
                echo "Test $i: $instructions instructions ✅"
            else
                echo "Test $i: $instructions instructions ⚠️  (over limit)"
            fi
        else
            echo "Test $i: FAILED ❌"
        fi
    done

    local average=$((total / num_tests))
    echo "Results: $passed/$num_tests passed"
    echo "Average instructions: $average"
    echo "Expected limit: $expected_max"
    echo
}

echo "Compiling push_swap and checker..."
make re > /dev/null 2>&1
make checker > /dev/null 2>&1

# Détection automatique de l'exécutable
PUSH_SWAP=""
if [ -f "./push_swap" ]; then
    PUSH_SWAP="./push_swap"
elif [ -f "./push_swap.out" ]; then
    PUSH_SWAP="./push_swap.out"
else
    echo "❌ No push_swap executable found!"
    exit 1
fi

echo "Using executable: $PUSH_SWAP"

# Détection automatique du checker (priorité à notre checker)
CHECKER=""
if [ -f "./checker" ]; then
    CHECKER="./checker"
elif [ -f "./checker_linux" ]; then
    CHECKER="./checker_linux"
else
    echo "❌ No checker found! Please compile the checker first."
    echo "Run: make checker"
    exit 1
fi

echo "Using checker: $CHECKER"
echo "✅ Compilation successful"
echo

# Tests de base
echo "=== BASIC FUNCTIONALITY TESTS ==="
test_case "Already sorted (3)" "1 2 3" 0
test_case "Reverse sorted (3)" "3 2 1" 3
test_case "Random (3)" "2 3 1" 3
test_case "Already sorted (5)" "1 2 3 4 5" 0
test_case "Reverse sorted (5)" "5 4 3 2 1" 12

# Tests de cas spéciaux
echo "=== SPECIAL CASES ==="
test_case "Two elements sorted" "1 2" 0
test_case "Two elements reverse" "2 1" 1
test_case "Single element" "42" 0

# Benchmarks par taille
echo "=== SIZE BENCHMARKS ==="

# 3 éléments (max 3 instructions)
benchmark_size 3 3

# 5 éléments (max 12 instructions)
benchmark_size 5 12

# 100 éléments (max ~700 instructions pour un bon algorithme)
echo "=== BENCHMARK: 100 elements (target: <700) ==="
numbers_100=$(generate_random 100)
instructions_100=$($PUSH_SWAP "$numbers_100" | wc -l)
result_100=$($PUSH_SWAP "$numbers_100" | $CHECKER "$numbers_100")
echo "Instructions: $instructions_100"
echo "Checker result: $result_100"
if [ "$result_100" = "OK" ]; then
    if [ $instructions_100 -lt 700 ]; then
        echo "✅ EXCELLENT (under 700)"
    elif [ $instructions_100 -lt 900 ]; then
        echo "✅ GOOD (under 900)"
    elif [ $instructions_100 -lt 1100 ]; then
        echo "⚠️  ACCEPTABLE (under 1100)"
    else
        echo "❌ POOR (over 1100)"
    fi
else
    echo "❌ FAILED"
fi
echo

# 500 éléments (max ~5500 instructions pour un bon algorithme)
echo "=== BENCHMARK: 500 elements (target: <5500) ==="
numbers_500=$(generate_random 500)
instructions_500=$($PUSH_SWAP "$numbers_500" | wc -l)
result_500=$($PUSH_SWAP "$numbers_500" | $CHECKER "$numbers_500")
echo "Instructions: $instructions_500"
echo "Checker result: $result_500"
if [ "$result_500" = "OK" ]; then
    if [ $instructions_500 -lt 5500 ]; then
        echo "✅ EXCELLENT (under 5500)"
    elif [ $instructions_500 -lt 7000 ]; then
        echo "✅ GOOD (under 7000)"
    elif [ $instructions_500 -lt 8500 ]; then
        echo "⚠️  ACCEPTABLE (under 8500)"
    else
        echo "❌ POOR (over 8500)"
    fi
else
    echo "❌ FAILED"
fi
echo

# Tests de cas extrêmes
echo "=== EDGE CASES ==="
test_case "Worst case 5 elements" "$(generate_reverse 5)" 12

echo "=== BENCHMARK COMPLETED ==="
