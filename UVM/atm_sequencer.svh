class atm_sequencer extends uvm_sequencer #(atm_sequence_item);

    `uvm_component_utils(atm_sequencer)

    function new(string name = "atm_sequencer", uvm_component parent = null);
        super.new(name, parent);
    endfunction
endclass