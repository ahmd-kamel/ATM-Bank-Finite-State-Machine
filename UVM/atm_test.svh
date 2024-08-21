class atm_test extends uvm_test;

    `uvm_component_utils(atm_test)
    function new(string name = "atm_test", uvm_component parent = null);
        super.new(name, parent);
    endfunction 
endclass