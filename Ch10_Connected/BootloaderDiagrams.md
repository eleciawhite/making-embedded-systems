```
%% Mermaid diagram, put this in mermaid.live if it doesn't show up as a flowchart.

%%{init: 
{'flowchart' : {
    'curve' : 'catmullrom'
    }}}%%


flowchart TD
    start{"Is there code in auxiliary flash?"}
    version{"Is the code in auxiliary flash newer?"}
    run["Run the code on the processor"]
    copy["Copy the new code to the processor"]
    reboot["Reboot"]
    start --> |Yes| version
    start --> |No| run
    version --> |Yes| copy
    copy --> reboot
    version --> |No| run
    reboot --> start

```