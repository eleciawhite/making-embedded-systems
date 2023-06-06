%%{
  init: {
    "sequence": {
        "mirrorActors": false,
        "diagramMarginX": 10,
        "diagramMarginY": 10,
        "boxTextMargin": 5,
        "noteMargin": 10,
        "messageMargin": 1,
        "wrap":true,
        "width":300
    }}
}%%


sequenceDiagram
    box rgb(255,240,240)
        participant ADC
    end 
    box rgb(240,255,240)
        participant MCU as processor
    end 

ADC->>MCU: ADC data ready interrupt 
activate MCU
note over MCU: ADC Data Ready ISR: kicks off SPI transfer
deactivate MCU
activate MCU
note over MCU: SPI TX empty ISR: Send TX
MCU->>ADC: data transfer
ADC->>MCU: 
deactivate MCU
activate MCU
note over MCU: SPI TX empty ISR: Send TX
MCU->>ADC: data transfer
ADC->>MCU: 
deactivate MCU
activate MCU
note over MCU: SPI TX empty ISR: Send TX
MCU->>ADC: data transfer
ADC->>MCU: 
deactivate MCU
activate MCU
note over MCU: SPI TX empty ISR: no more bytes. Signal new ADC samples are ready for use.
deactivate MCU
ADC->>MCU: ADC data ready interrupt 
note over MCU: ...
