class atm_sequence extends uvm_sequence;

    `uvm_object_utils(atm_sequence)

    function new(string name = "atm_sequence");
        super.new(name);
    endfunction
endclass