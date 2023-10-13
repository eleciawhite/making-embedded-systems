// gcc averaging.c -o ave
//  ./ave

#include <stdio.h>
#include <stdint.h>

struct sAve {
  int32_t blockSum;
  uint16_t numSamples;
};

void ClearAverage(struct sAve *ave) {
  ave->blockSum = 0;
  ave->numSamples = 0;
}
void AddSampleToAverage(struct sAve *ave, int16_t newSample) {
  ave->blockSum += newSample;
  ave->numSamples++;
}

int16_t GetAverage(struct sAve *ave) {
  int16_t average = ave->blockSum/ave->numSamples;
  return average;
}

float GetAverageF(struct sAve *ave) {
  float average = (float)(ave->blockSum)/ave->numSamples;
  return average;
}

// have all of the samples ready, sum them up, then divide by the number
int16_t PlainOldAverage(int16_t* samples, uint16_t sampleLength)
{
  int i;
  int32_t sum = 0; 
  for (i = 0; i < sampleLength; i++)
  {
    sum += samples[i];
  }
  return sum/sampleLength;
}

// have all of the samples ready, sum them up, then divide by the number
int16_t averageWithStruct(int16_t* samples, uint16_t sampleLength)
{
  int i;
  struct sAve ave;
  ClearAverage(&ave);
  for (i = 0; i < sampleLength; i++)
  {
    AddSampleToAverage(&ave, samples[i]);
  }
  return GetAverage(&ave);
}

float averageWithStructF(int16_t* samples, uint16_t sampleLength)
{
  int i;
  struct sAve ave;
  ClearAverage(&ave);
  for (i = 0; i < sampleLength; i++)
  {
    AddSampleToAverage(&ave, samples[i]);
  }
  return GetAverageF(&ave);
}


float PlainGetVariance(int16_t* samples, uint16_t numSamples, int16_t mean) {
  uint32_t sumSquares = 0;
  int32_t tmp;
  uint32_t i;

  for (i = 0; i < numSamples; i++) {
    tmp = samples[i] - mean;
    sumSquares += tmp*tmp;
  }
  return ((float)sumSquares/numSamples);
}

struct sVar {
  int32_t sum;
  uint64_t sumSquares;
  uint16_t numSamples;
};
void ClearVariance(struct sVar *var) {
  var->sum = 0; var->numSamples = 0; var->sumSquares = 0;
}
void AddSampleToVariance (struct sVar *var, int16_t newSample) {
  var->sum += newSample;
  var->sumSquares += newSample*newSample;
  var->numSamples++;
}
float GetVariance(struct sVar *var, float *average) {
  float variance;
  *average = (float) var->sum/var->numSamples;  
  variance = (var->sumSquares - (var->sum * (*average))) 
                       /(var->numSamples-1);  
  return variance;
}

float varianceWithStruct(int16_t* samples, uint16_t sampleLength, float* averageResult)
{
  int i;
  struct sVar var;
  ClearVariance(&var);
  for (i = 0; i < sampleLength; i++)
  {
    AddSampleToVariance(&var, samples[i]);
  }

  return GetVariance(&var, averageResult);
}


struct sWelfordVar {
  int16_t mean;
  int32_t M2;
  uint16_t numSamples;
};
void ClearWelfordVariance(struct sWelfordVar *var) {
  var->mean = 0; var->M2 = 0; var->numSamples = 0;
}

void AddSampleToWelfordVariance(struct sWelfordVar *var, int16_t newSample) {
  int16_t delta = newSample - var->mean;
  var->numSamples++;
  var->mean += delta/var->numSamples;
  var->M2 += delta * (newSample - var->mean); // uses the new mean
}
uint16_t GetWelfordVariance(struct sWelfordVar *var, int16_t *average) {
  uint16_t variance = var->M2/var->numSamples;
  *average = var->mean; // running average already calculated
  return variance;
}

uint16_t welfordVarianceWithStruct(int16_t* samples, uint16_t sampleLength, int16_t* averageResult)
{
  int i;
  struct sWelfordVar var;
  ClearWelfordVariance(&var);
  for (i = 0; i < sampleLength; i++)
  {
    AddSampleToWelfordVariance(&var, samples[i]);
  }
  return GetWelfordVariance(&var, averageResult);
}


void TestAverages() 
{

  int16_t samples20[20];
  int sampleLength = 20;
  for (int i = 0; i < sampleLength; i++)
  {
    samples20[i] = i;
  }

  printf("PlainOldAverage: %d\n", 
    PlainOldAverage(samples20, sampleLength));

  printf("averageWithStruct: %d\n", 
    averageWithStruct(samples20, sampleLength));

  printf("averageWithStructF: %.2f \n", 
    averageWithStructF(samples20, sampleLength));  

  printf("Variance: %.2f \n", 
    PlainGetVariance(samples20, sampleLength, 
    PlainOldAverage(samples20, sampleLength)));

  float average;
  float variance = varianceWithStruct(samples20, sampleLength, &average);
  printf("VarianceWithStruct: %.2f ave %.2f\n", 
    variance, average);

  uint16_t waverage;
  uint16_t wvariance = welfordVarianceWithStruct(samples20, sampleLength, &waverage);
  printf("WelfordVarianceWithStruct: %d ave %d\n", 
    wvariance, waverage);
  printf("  (Note: That one is wrong because of integer truncation.) \n"); 

}


int main()
{ 
  TestAverages();
  return 1;
}