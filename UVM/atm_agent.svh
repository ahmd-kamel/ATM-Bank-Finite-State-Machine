class atm_agent extends uvm_agent;

    `uvm_component_utils(atm_agent)

    function (string name = "atm_agent", uvm_component parent = null);
        super.new(name, parent);
    endfunction
endclass 