#define vRef 3.30
#define ADC_Resolution 4095
#define LM35_Per_Degree_Volt 0.01
#define Zero_Deg_ADC_Value -89.00
int fan1=3;
int fan2=4;
int fan3=5;
int fan4=6;

const int lm35_pin = A0;                /* Connect LM35 out pin to A0 of ESP32*/
float _temperature, temp_val, ADC_Per_Degree_Val;
int temp_adc_val;

void setup(void){
  Serial.begin(9600);
  ADC_Per_Degree_Val = (ADC_Resolution/vRef)*LM35_Per_Degree_Volt;
}

void loop(void){ 
  for (int i = 0; i < 10; i++) {
    temp_adc_val += analogRead(lm35_pin);  /* Read ADC value */
    delay(10);
  }
  temp_adc_val = temp_adc_val/10.0;

  temp_adc_val = temp_adc_val - Zero_Deg_ADC_Value;
  temp_adc_val=(temp_adc_val/ADC_Per_Degree_Val);
  Serial.print("v);           /* Print Temperature on the serial window */
  Serial.print("°C\n");
  delay(100);

if(temp_adc_val>26)
{
digitalWrite(fan1,HIGH);
digitalWrite(fan2,LOW);
digitalWrite(fan3,LOW);
digitalWrite(fan4,LOW);

}
else if(temp_adc_val>24)
{
digitalWrite(fan2,HIGH);
digitalWrite(fan1,LOW);
digitalWrite(fan3,LOW);
digitalWrite(fan4,LOW);
}

else if(temp_adc_val>22)
{
digitalWrite(fan3,HIGH);
digitalWrite(fan1,LOW);
digitalWrite(fan2,LOW);
digitalWrite(fan4,LOW);

}
else if(temp_adc_val>18)
{
digitalWrite(fan4,HIGH);
digitalWrite(fan1,LOW);
digitalWrite(fan2,LOW);
digitalWrite(fan3,LOW);
}
else
{
digitalWrite(fan1,LOW);
digitalWrite(fan2,LOW);
digitalWrite(fan3,LOW);
digitalWrite(fan4,LOW);
}
}
