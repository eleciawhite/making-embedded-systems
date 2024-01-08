```
%% Mermaid diagram, put this in mermaid.live if it doesn't show up as a decision tree.

%%{init: 
{'flowchart' : {
    'curve' : 'catmullrom'
    }}}%%

flowchart TD
    Start{{"Is (clockIn/goalInterruptFreq) factorable into <b>prescaler</b> and <b>compare</b>?"}} 
    MinPrescale[Determine minimum <b>prescaler</b>.\nRound up to nearest integer.] 
    PrescaleFit{{Does <b>prescaler</b> fit in the processor's prescaler register?}} 
    CalcCompare[Calculate <b>compare</b> value.\nRound to nearest integer.]
    AcceptableError{{Is the error acceptable?}}
    MultTwoOk{{Would doubling the <b>prescaler</b>\nfit in register?}}
    MultTwo[Multiply <b>prescale</b> by 2. \nFind <b>compare</b> needed to\n approach to goalInterruptFreq.]
    Brute[Brute force solution]
    Exception
    Done[Done]
    Done2[Done]

    Start --> |Yes|Done2
    Start --> |No| MinPrescale
    
    MinPrescale --> PrescaleFit
    PrescaleFit -->|No| Exception
    PrescaleFit --> |Yes| CalcCompare
    CalcCompare --> AcceptableError
    AcceptableError --> |No| MultTwoOk
    AcceptableError --> |Yes| Done
    MultTwoOk --> |No| Brute
    MultTwoOk --> |Yes| MultTwo
    MultTwo --> AcceptableError
``````