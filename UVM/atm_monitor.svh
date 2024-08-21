class atm_monitor extends uvm_monitor;

    `uvm_component_utils(atm_monitor)

    function new(string name = "atm_monitor", uvm_component parent = null);
        super.new(name, parent);
    endfunction
endclass 