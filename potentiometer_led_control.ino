/*
 * 可調式電阻控制 LED 亮度
 * 創建日期: 2025年4月18日
 * 
 * 此程式使用可調式電阻（電位計）來控制 LED 的亮度。
 * 電位計連接到類比輸入針腳 A0，LED 連接到 PWM 輸出針腳 9。
 * 當電位計旋轉時，LED 的亮度會相應變化。
 */

// 定義針腳
const int potPin = A0;    // 可調式電阻連接到類比輸入 A0
const int ledPin = 9;     // LED 連接到 PWM 輸出針腳 9

// 變數
int potValue = 0;        // 用於儲存可調式電阻的值
int ledValue = 0;        // 用於儲存 LED 的亮度值

void setup() {
  // 初始化序列通訊，波特率為 9600
  Serial.begin(9600);
  
  // 設定 LED 針腳為輸出模式
  pinMode(ledPin, OUTPUT);
  
  // 設定可調式電阻針腳為輸入模式
  pinMode(potPin, INPUT);
}

void loop() {
  // 讀取可調式電阻的值 (0-1023)
  potValue = analogRead(potPin);
  
  // 將可調式電阻的值 (0-1023) 映射到 LED 亮度值 (0-255)
  ledValue = map(potValue, 0, 1023, 0, 255);
  
  // 設定 LED 的亮度
  analogWrite(ledPin, ledValue);
  
  // 在序列監視器上顯示數值
  Serial.print("電位計數值: ");
  Serial.print(potValue);
  Serial.print("\t LED 亮度: ");
  Serial.println(ledValue);
  
  // 短暫延遲以提高穩定性
  delay(100);
}