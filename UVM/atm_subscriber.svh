class atm_subscriber extends uvm_subscriber;

    `uvm_component_utils(atm_subscriber)

    function new(string name = "atm_subscriber", uvm_component parent = null);
        super.new(name, parent);
    endfunction
endclass