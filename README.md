# AD5292_Digital_Potentiometer
An Arduino Library for Controlling the AD5292 Digital Potentiometer



#### Wiring Table

| AD5292 Pin # | AD Name | Arduino Pin | Comment |
|------------|-------------|-----|---|
| 1 | RESET | ICSP-5 | Reset |
| 2 | V$_{SS}$ | $\rightarrow $ GND | Typically to Ground (⏚) |
| 3 | A | V$_\text{SOURCE}$ | Max: $\pm \text{V}_\text{DD}$ |
| 4 | W | $\rightarrow LED \rightarrow 220 \Omega \rightarrow \text{Gnd}$ |  |
| 5 | B | $\rightarrow $ GND | Max: $\pm \text{V}_\text{SS}$ |
| 6 | V$_{DD}$ | ICSP-2 | +V$_{CC}$ |
| 7 | EXT_CAP |  | See [datasheet](https://github.com/elec3647/AD5292_Digital_Potentiometer/raw/master/from_analog/AD5291_5292.pdf). |
| 8 | $V_\text{LOGIC}$ | $\rightarrow V_{CC}$ | 3.3 V or 5 V |
| 9 | GND | ICSP-6 | Gnd (⏚) |
| 10 | DIN | ICSP-4 | MOSI |
| 11 | SCLK        | ICSP-3 | SCK |
| 12 | SYNC        | 10 | SS |
| 13 | SDO | ICSP-1 | MISO |
| 14 | RDY | 6 | dataReadyPin |



<img src="/Users/cookie/Library/Application Support/typora-user-images/image-20191119170726260.png" alt="image-20191119170726260" style="zoom:30%;" />

