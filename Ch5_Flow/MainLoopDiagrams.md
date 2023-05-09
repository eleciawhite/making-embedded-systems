%% Mermaid diagram, put this in mermaid.live if it doesn't show up as a decision tree.


%%{
  init: {
    "sequence": {
        "mirrorActors": false,
        "diagramMarginX": 10,
        "diagramMarginY": 10,
        "boxTextMargin": 5,
        "noteMargin": 10,
        "messageMargin": 35,
        "messageAlign":"left",
        "wrap":true,
        "width":85
    }}
}%%


%% Main 1: initial diagram
sequenceDiagram
    participant main as main loop
    participant LED as LED code 
    participant delay as delay code
    Note left of main: time ↓
    main->>LED: toggle
    main->>+delay: delay
    delay->>-main:done
    Note over main: repeat

    
%% Main 2: with inputs and outputs
sequenceDiagram
    participant main as main loop
    participant LED as LED code
    participant delay as delay code
    participant inputs as input code
    participant outputs as output code
    Note left of main: time ↓
    main->>inputs: read
    main->>outputs: write
    main->>LED: toggle
    main->>+delay: delay
    delay-->>-main:done
    Note over main: repeat
    
    
%% Main 3: Timer interrupt for LED
sequenceDiagram
    participant main as main loop
    participant watchdog as watchdog code
    participant delay as delay code
    participant inputs as input code
    participant outputs as output code
    box rgb(250,240,240)
      participant timer as timer interrupt
      participant LED as LED code
    end
    Note left of main: time ↓
    main->>inputs: read
    timer->>LED:toggle
    main->>outputs: write
    main->>watchdog:pet
    timer->>LED:toggle
    Note over main: repeat
    Note over timer,LED: asynchronous


%% Main 4: Interrupts do everything
sequenceDiagram
    box
    participant main as main loop
    participant watchdog as watchdog code
    end
    box rgb(250,240,240)
    participant timer as timer interrupt
    participant LED as LED code
    end
    box rgb(250,240,240)
    participant dataAvail as data interrupt
    participant inputs as input code
    end
    box rgb(250,240,240)
    participant outputReady as output interrupt
    participant outputs as output code
    end
    Note left of main: time ↓
    timer-)LED:toggle
    Note over timer,LED: asynchronous
    main->>watchdog:pet
    main->>main:sleep
    dataAvail-)inputs:read
    Note over dataAvail,inputs: asynchronous
    main->>watchdog:pet
    main->>main:sleep
    outputReady-)outputs:write
    Note over outputReady,outputs: asynchronous
    main->>watchdog:pet
    main->>main:sleep
    Note over main: wakes after any interrupt


%% Main 5: Interrupts cause events
sequenceDiagram
    box
    participant main as main loop
    participant watchdog as watchdog code
    participant inputs as input code
    participant LED as LED code
    participant outputs as output code
    end
    box rgb(250,240,240)
    participant timer as timer interrupt
    end
    box rgb(250,240,240)
    participant dataAvail as data interrupt
    end
    box rgb(250,240,240)
    participant outputReady as output interrupt
    end
    Note left of main: time ↓
    timer-)main:toggle event
    Note over timer: async
    main->>LED:toggle
    main->>watchdog:pet
    main->>main:sleep
    dataAvail-)main:read event
    Note over dataAvail: async
    main->>inputs:read
    main->>watchdog:pet
    main->>main:sleep
    outputReady-)main:write event
    Note over outputReady: async
    main->>outputs:write
    main->>watchdog:pet
    main->>main:sleep
    Note over main: wakes after any interrupt

%% Main 6: Tiny scheduler
sequenceDiagram
    box rgb(250,240,240)
    participant systick as systick interrupt
    end
    participant main as main loop
    participant watchdog as watchdog code
    participant inputsCallback as input callback
    participant inputs as input code
    participant outputsCallback as output callback
    participant outputs as output code
    participant LEDCallback as LED callback
    participant LED as LED code
    Note left of systick: time ↓
    systick-)main: update clock
    main->>inputsCallback:if time, call input callback
    inputsCallback->>inputs:read
    main->>outputsCallback:if time, call output callback 
    outputsCallback->>outputs:write
    main->>LEDCallback:if time, call LED callback
    LEDCallback->>LED:toggle
    main->>watchdog:pet
    main->>main:sleep
    Note over main: wake at time of next scheduled task
    Note over systick: async



%% Main 7: Active objects
sequenceDiagram
sequenceDiagram
    box
    participant main as idle task
    participant watchdog as watchdog code
    end
    box rgb(240,255,255)
    participant timer as timer interrupt
    participant LEDTask as LED task
    participant LED as LED code
    end
    box rgb(255,255,240)
    participant dataAvail as data interrupt
    participant inputTask as input task
    participant inputs as input code
    end
    box rgb(240,240,240)
    participant outputTask as output task
    participant outputs as output code
    end
    Note left of main: time ↓
    timer-)LEDTask:event
    Note over timer: async
    LEDTask->>LED:toggle
    main->>watchdog:pet
    main->>main:sleep
    dataAvail-)inputTask:event
    Note over dataAvail: async
    inputTask->>inputs:read
    inputTask->>outputTask:event
    outputTask-)outputs:write
    main->>watchdog:pet
    main->>main:sleep
    Note over main: wakes after any interrupt

