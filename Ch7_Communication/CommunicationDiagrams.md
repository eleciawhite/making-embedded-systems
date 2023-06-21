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

%% SPI with data ready interrupt
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



%% SPI with DMA
sequenceDiagram
    box rgb(255,240,240)
        participant ADC
    end 
    box rgb(240,240,255)
        participant DMA as DMA
    end 
    box rgb(240,255,240)
        participant MCU as processor core
    end 

ADC->>MCU: ADC data ready interrupt 
activate MCU
note right of MCU: ADC Data Ready ISR: kicks off SPI DMA transfer
deactivate MCU
DMA->>ADC: data transfer
ADC->>DMA: 
DMA->>ADC: data transfer
ADC->>DMA: 
DMA->>ADC: data transfer
ADC->>DMA: 
DMA->>MCU: DMA complete
activate MCU
note right of MCU: DMA complete ISR. Signal runtime new ADC samples are ready for use.

deactivate MCU
ADC->>MCU: ADC data ready interrupt 
note over MCU: ...
