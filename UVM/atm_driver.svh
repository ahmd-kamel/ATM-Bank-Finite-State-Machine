class atm_driver extends uvm_driver #(atm_sequence_item);

    `uvm_component_utils(atm_driver)
    function (string name = "atm_driver", uvm_component parent = null);
        super.new(name, parent);
    endfunction 
endclass