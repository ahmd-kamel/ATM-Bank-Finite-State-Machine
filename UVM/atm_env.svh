class atm_env extends uvm_env;
    `uvm_component_utils(atm_env)

    function (string name = "atm_env", uvm_component parent = null);
        super.new(name, parent);
    endfunction
endclass