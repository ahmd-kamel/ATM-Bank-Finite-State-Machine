class atm_scoreboard extends uvm_scoreboard;

    `uvm_component_utils(atm_scoreboard)

    function new(string name = "atm_scoreboard", uvm_component parent = null);
        super.new(name, parent);
    endfunction
endclass