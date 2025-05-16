#include <stdio.h>
#include <stdbool.h>
#include "busca_seq_ordenada.h"
#include "busca_binaria.h"
#include "recursao.h"

#define RUN_TEST(name, expr, expected)                               \
    do {                                                             \
        long long result = (long long)(expr);                        \
        long long exp = (long long)(expected);                       \
        printf("%-45s : %s (Got: %lld, Expected: %lld)\n", name,      \
               (result == exp) ? "OK" : "FAIL", result, exp);        \
    } while(0)


int bad_version = 4;
bool isBadVersion(int version) {
    return version >= bad_version;
}

int main() {
    printf("--- Iniciando Testes ---\n");

    printf("\n--- Testes para busca_binaria ---\n");
    int n_versions1 = 5;
    bad_version = 4;
    RUN_TEST("Busca Binaria (n=5, bad=4)", busca_binaria(n_versions1), 4);

    int n_versions2 = 10;
    bad_version = 7;
    RUN_TEST("Busca Binaria (n=10, bad=7)", busca_binaria(n_versions2), 7);

    int n_versions3 = 1;
    bad_version = 1;
    RUN_TEST("Busca Binaria (n=1, bad=1)", busca_binaria(n_versions3), 1);

    int n_versions4 = 10;
    bad_version = 11;
    RUN_TEST("Busca Binaria (n=10, sem defeito)", busca_binaria(n_versions4), 11);
    
    int n_versions5 = 0;
    RUN_TEST("Busca Binaria (n=0)", busca_binaria(n_versions5), 0);



    printf("\n--- Testes para conta_especialidades_distintas ---\n");
    int arr1[] = {4, 2, 1, 4, 2, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    RUN_TEST("Conta Especialidades (ex1: {4,2,1,4,2,1})", conta_especialidades_distintas(arr1, n1), 3);

    int arr2[] = {1, 1, 1, 1, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    RUN_TEST("Conta Especialidades (ex2: {1,1,1,1,1})", conta_especialidades_distintas(arr2, n2), 1);

    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    RUN_TEST("Conta Especialidades (ex3: {1,2,3,4,5})", conta_especialidades_distintas(arr3, n3), 5);

    int arr4[] = {};
    int n4 = 0;
    RUN_TEST("Conta Especialidades (array vazio)", conta_especialidades_distintas(arr4, n4), 0);
    
    int arr5[] = {5, 1, 3, 2, 3, 1, 5, 2, 4};
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    RUN_TEST("Conta Especialidades (ex5: {5,1,3,2,3,1,5,2,4})", conta_especialidades_distintas(arr5, n5), 5);



    printf("\n--- Testes para busca_seq_ordenada (em array ordenado) ---\n");
    int arr_sorted_seq[] = {10, 20, 30, 40, 50};
    int n_sorted_seq = sizeof(arr_sorted_seq)/sizeof(arr_sorted_seq[0]);
    RUN_TEST("Busca Seq Ordenada ({10,20,30,40,50}, alvo=30)", busca_seq_ordenada(arr_sorted_seq, n_sorted_seq, 30), 2);
    RUN_TEST("Busca Seq Ordenada ({10,20,30,40,50}, alvo=10)", busca_seq_ordenada(arr_sorted_seq, n_sorted_seq, 10), 0);
    RUN_TEST("Busca Seq Ordenada ({10,20,30,40,50}, alvo=50)", busca_seq_ordenada(arr_sorted_seq, n_sorted_seq, 50), 4);
    RUN_TEST("Busca Seq Ordenada ({10,20,30,40,50}, alvo=5)", busca_seq_ordenada(arr_sorted_seq, n_sorted_seq, 5), -1);
    RUN_TEST("Busca Seq Ordenada ({10,20,30,40,50}, alvo=55)", busca_seq_ordenada(arr_sorted_seq, n_sorted_seq, 55), -1);
    int arr_empty_seq[] = {};
    RUN_TEST("Busca Seq Ordenada (array vazio, alvo=10)", busca_seq_ordenada(arr_empty_seq, 0, 10), -1);



    printf("\n--- Testes para recursao (contagem de caracteres) ---\n");
    RUN_TEST("Recursao (banana, 'a')", recursao("banana", 'a'), 3);
    RUN_TEST("Recursao (zzzz, 'z')", recursao("zzzz", 'z'), 4);
    RUN_TEST("Recursao (abc, 'x')", recursao("abc", 'x'), 0);
    RUN_TEST("Recursao (array vazio, 'a')", recursao("", 'a'), 0);



    printf("\n--- Testes Concluidos ---\n");
    return 0;
}