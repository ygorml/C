#include <math.h>
#include <stdio.h>

/* Constantes globais */
const double velocidadeLuz = 3E8;
const float pi = 3.1415;

/* Variaveis globais */
float   valorGraus = 0.0,
        valordB = 0.0,
        valorAdimensional = 0.0;

/* Protótipo das Funções */

float grausParaRadianos(float valorGraus);
float dBParaAdimensional(float valordB);
float adimensionalParadB(float valorAdimensional);

/* Main */
int main() {

float   sigmaTarget = 1.0,
        sigmaClutter = 0.0,
        sigmaClutterdB = 0.0,
        relacaoSN = 20.0,
        feixeHorizontalGraus = 0.0,
        feixeHorizontalRadianos = 0.0,
        distanciaRadarAlvo = 0.0,
        sigmaZero = 0.0,
        larguraPulso = 0.0,
        celulaRadar = 0.0,
        sigmazerodB = 0.0;

int escolhaCelulaRadar = 0;

printf("==== Cálculo de Atenuação de Clutter ====\n");
printf("Cálculo da Célular Radar através do\n");
printf("1) - Valor \"minimum range\"\n");
printf("2) - Valor de LP\n");
printf("=========================================\n");

printf("Escolha sua opção: \n");
scanf("%d", &escolhaCelulaRadar);

if (escolhaCelulaRadar == 1) {
    printf("Digite o Minimum Range: \n");
    scanf("%f", &celulaRadar);    
}
else if(escolhaCelulaRadar == 2) {
    printf("Digite a LP (em notação científica, em segundos): \n");
    scanf("%f", &larguraPulso);
    celulaRadar = (velocidadeLuz * larguraPulso) / 2;
}
else {
    printf("Valor invalido!\n");
}
printf("Digite o valor de sigma zero (em dB): \n");
scanf("%f", &sigmazerodB);

printf("Digite a área da seção reta do alvo (em m2): \n");
scanf(" %f", &sigmaTarget);

printf("Digite a distância radar-alvo (em km): \n");
scanf(" %f", &distanciaRadarAlvo);

printf("Digite o valor do feixe horizontal (graus): \n");
scanf(" %f", &feixeHorizontalGraus);

distanciaRadarAlvo *= 1E3;
feixeHorizontalRadianos = grausParaRadianos(feixeHorizontalGraus);
sigmaZero = dBParaAdimensional(sigmazerodB);

sigmaClutter = sigmaZero * celulaRadar * distanciaRadarAlvo * feixeHorizontalRadianos * (relacaoSN/sigmaTarget);
sigmaClutterdB = adimensionalParadB(sigmaClutter);

printf("O valor da atenuação de clutter, em dB, é %.2f (dB)", sigmaClutterdB);

return 0;

} /* End main */

/* Desenvolvimento das Funções */

float grausParaRadianos(float valorGraus) {
    float valorRadianos = (2 * pi * valorGraus)/360;
    return valorRadianos;
}

float dBParaAdimensional(float valordB) {
    float valorAdimensional = powf(10.0, (valordB/10.0));
    return valorAdimensional;
}

float adimensionalParadB(float valorAdimensional) {
    float valordB = 10*log10(valorAdimensional);
    return valordB;
}
