# SPI with data ready interrupt
```mermaid
%% Mermaid diagram, put this in mermaid.live if it doesn't show as images
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

note left of ADC: time ↓
ADC->>MCU: ADC data ready interrupt 
activate MCU
note right of MCU: ADC Data Ready ISR:<br>kicks off SPI transfer
deactivate MCU
activate MCU

note right of MCU: SPI TX empty ISR:<br>Send TX
MCU-->>ADC: data transfer
ADC-->>MCU: 
deactivate MCU
activate MCU
note right of MCU: SPI TX empty ISR:<br>Send TX
MCU-->>ADC: data transfer
ADC-->>MCU: 
deactivate MCU
activate MCU
note right of MCU: SPI TX empty ISR:<br>Send TX
MCU-->>ADC: data transfer
ADC-->>MCU: 
deactivate MCU
activate MCU
note right of MCU: SPI TX empty ISR:<br> No more bytes.<br>Signal new ADC <br>samples are ready for use.
deactivate MCU
ADC->>MCU: ADC data ready interrupt 
activate MCU
ADC->MCU:<br> 
deactivate MCU
```

# SPI with DMA
```mermaid
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

%% SPI with DMA
sequenceDiagram
    box rgb(250,240,240)
        participant ADC
    end 
    box rgb(240,250,240)
        participant DMA as DMA
    end 
    box rgb(240,240,250)
        participant MCU as Processor core
    end 

note left of ADC: time ↓
MCU->>DMA: Configure source and memory
ADC->>MCU: ADC data ready interrupt 
activate MCU
note right of MCU: ADC Data Ready ISR:<br>kicks off SPI DMA transfer
deactivate MCU
DMA-->>ADC: data transfer
ADC-->>DMA: 
DMA-->>ADC: data transfer
ADC-->>DMA: 
DMA-->>ADC: data transfer
ADC-->>DMA: 
DMA->>MCU: DMA complete
activate MCU
note right of MCU: DMA complete ISR:<br>Signals runtime new ADC <br>samples are ready for use.

deactivate MCU
ADC->>MCU: ADC data ready interrupt 
activate MCU
ADC->MCU:<br> 
deactivate MCU

```