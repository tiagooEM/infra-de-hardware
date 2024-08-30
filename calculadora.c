#include <stdio.h>
#include <math.h>

void decimalParaBinario(int n) {
    printf("Conversao de decimal para binario:\n");
    int binario[32];
    int i = 0;
    while(n > 0) {
        binario[i] = n % 2;
        printf("Passo %d: %d %% 2 = %d (resto)\n", i+1, n, binario[i]);
        n = n / 2;
        i++;
    }
    printf("Resultado em binario: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n\n");
}

void decimalParaOctal(int n) {
    printf("Conversao de decimal para octal:\n");
    int octal[32];
    int i = 0;
    while(n > 0) {
        octal[i] = n % 8;
        printf("Passo %d: %d %% 8 = %d (resto)\n", i+1, n, octal[i]);
        n = n / 8;
        i++;
    }
    printf("Resultado em octal: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n\n");
}

void decimalParaHexadecimal(int n) {
    printf("Conversao de decimal para hexadecimal:\n");
    char hexadecimal[32];
    int i = 0;
    while(n > 0) {
        int temp = n % 16;
        printf("Passo %d: %d %% 16 = %d (resto)\n", i+1, n, temp);
        if(temp < 10) {
            hexadecimal[i] = temp + 48;
        } else {
            hexadecimal[i] = temp + 55; 
        }
        n = n / 16;
        i++;
    }
    printf("Resultado em hexadecimal: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n\n");
}

void decimalParaBCD(int n) {
    printf("Conversao de decimal para BCD:\n");
    while(n > 0) {
        int digito = n % 10;
        printf("Digito: %d, BCD: ", digito);
        for(int i = 3; i >= 0; i--) {
            printf("%d", (digito >> i) & 1);
        }
        printf("\n");
        n = n / 10;
    }
    printf("\n");
}

void decimalParaComplemento2(int n) {
    printf("Conversao de decimal para complemento de 2 (16 bits):\n");
    unsigned short int binario[16];
    int i = 0;
    unsigned short int numero = n;

    if(n < 0) {
        numero = pow(2, 16) + n;
        printf("Numero negativo detectado. Convertendo para complemento de 2:\n");
        printf("Numero em decimal: %d\n", numero);
    }

    for(i = 0; i < 16; i++) {
        binario[i] = (numero >> i) & 1;
    }

    printf("Resultado em complemento de 2 (16 bits): ");
    for(int j = 15; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n\n");
}

void decimalParaFloat(float numero) {
    printf("Conversao de decimal real para formato float (32 bits):\n");
    unsigned int *ptr = (unsigned int*)&numero;
    unsigned int bits = *ptr;

    unsigned int sinal = (bits >> 31) & 1;
    unsigned int expoente = (bits >> 23) & 0xFF;
    unsigned int fracao = bits & 0x7FFFFF;

    printf("Bits: %08X\n", bits);
    printf("Sinal: %d\n", sinal);
    printf("Expoente (sem vies): %d\n", expoente - 127);
    printf("Expoente (com vies): %d\n", expoente);
    printf("Fracao: 0x%X\n\n", fracao);
}

void decimalParaDouble(double numero) {
    printf("Conversao de decimal real para formato double (64 bits):\n");
    unsigned long long *ptr = (unsigned long long*)&numero;
    unsigned long long bits = *ptr;

    unsigned long long sinal = (bits >> 63) & 1;
    unsigned long long expoente = (bits >> 52) & 0x7FF;
    unsigned long long fracao = bits & 0xFFFFFFFFFFFFF;

    printf("Bits: %016llX\n", bits);
    printf("Sinal: %llu\n", sinal);
    printf("Expoente (sem vies): %lld\n", expoente - 1023);
    printf("Expoente (com vies): %llu\n", expoente);
    printf("Fracao: 0x%llX\n\n");
}

int main() {
    int escolha, num;
    float num_float;
    double num_double;

    do {
        printf("Calculadora Programador Didatica\n");
        printf("Escolha uma operacao:\n");
        printf("1 - Converter decimal para base 2 (binario)\n");
        printf("2 - Converter decimal para base 8 (octal)\n");
        printf("3 - Converter decimal para base 16 (hexadecimal)\n");
        printf("4 - Converter decimal para codigo BCD\n");
        printf("5 - Converter decimal para complemento de 2 (16 bits)\n");
        printf("6 - Converter numero real para float (32 bits)\n");
        printf("7 - Converter numero real para double (64 bits)\n");
        printf("8 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch(escolha) {
            case 1:
                printf("Digite o numero decimal: ");
                scanf("%d", &num);
                decimalParaBinario(num);
                break;
            case 2:
                printf("Digite o numero decimal: ");
                scanf("%d", &num);
                decimalParaOctal(num);
                break;
            case 3:
                printf("Digite o numero decimal: ");
                scanf("%d", &num);
                decimalParaHexadecimal(num);
                break;
            case 4:
                printf("Digite o numero decimal: ");
                scanf("%d", &num);
                decimalParaBCD(num);
                break;
            case 5:
                printf("Digite o numero decimal: ");
                scanf("%d", &num);
                decimalParaComplemento2(num);
                break;
            case 6:
                printf("Digite o numero real: ");
                scanf("%f", &num_float);
                decimalParaFloat(num_float);
                break;
            case 7:
                printf("Digite o numero real: ");
                scanf("%lf", &num_double);
                decimalParaDouble(num_double);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(escolha != 8);

    return 0;
}
