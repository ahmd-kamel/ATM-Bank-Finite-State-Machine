class atm_sequence_item extends uvm_sequence_item;

    `uvm_object_utils(atm_sequence_item)

    function new(string name = "atm_sequence_item");
        super.new(name);
    endfunction
endclass