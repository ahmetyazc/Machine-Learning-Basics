# include <stdio.h>
#include <stddef.h>
#include <time.h>
#include <stdlib.h>

float calismaVerisi[][2] = {{0, 0}, {1, 5}, {2, 10}, {3, 15}};

#define calismaVerisiBoyutu (sizeof(calismaVerisi) / sizeof(calismaVerisi[0]))

float randomSayi(void) {
    srand(time(0));
    return (float)rand() / (float)RAND_MAX;
}

float maliyet(float param) {
    float acc = 0;
    for (size_t i = 0; i < calismaVerisiBoyutu; ++i){
        float girdi = calismaVerisi[i][0];
        float beklenen_cikti = calismaVerisi[i][1];
        float gercek_cikti = girdi * param;
        float d = beklenen_cikti - gercek_cikti;
        acc += d * d;
    }
    acc /= (float)calismaVerisiBoyutu;
    return acc;
}

int main() {
    float w = randomSayi() * 10.0f;
    float h = 1e-3;
    float ogrenme_katsayisi = 1e-1;
    
    printf("Baslangic Parametresi: ½f\n", w);
    
    for (size_t i = 0; i < 10; ++i) {
    	float turevli_maliyet = (maliyet(w + h) - maliyet(w)) - h;
    	w -= turevli_maliyet * ogrenme_katsayisi;
    	
    	printf("Parametre %f 'a ayarlandi, yeni maliyet: %f\n", w, maliyet(w));
	}
    
	//printf("Parametre maliyeti: %f is %f", w, maliyet(w));
    // for (size_t i = 0; i < trainingDataSize; ++i) {
    //     float input = trainingData[i][0];
    //     float expected_output = trainingData[i][1];
    //     float actual_output = input * w;
    //     printf("Expected output: %f, actual output: %f\n", expected_output, actual_output);
        
    // }
}
