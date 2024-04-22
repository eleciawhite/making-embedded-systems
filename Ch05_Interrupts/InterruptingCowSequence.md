# Interrupting Cow Knock-Knock Joke
```mermaid
%% Mermaid diagram, put this in mermaid.live if it doesn't show

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
    participant A as Me
    participant B as You
autonumber
Note left of A: time ↓

activate A
A->>B: Knock!
A->>B: Knock!
deactivate A
activate B
B->>A: Who's there?
deactivate B
activate A
A->>B: Interrupting cow.
deactivate A

activate B
B->>A: Interrupting 
B->>A: cow
activate A
A->>B: Mooooo!
deactivate A
B-->>A: who?

deactivate B

```