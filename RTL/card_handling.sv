module card_handling #(
    parameter CARD_WIDTH = 6,
              PASS_WIDTH = 16,
              BLNC_WIDTH = 20,
              USERS_NUMS = 10
)(
    input wire clk,
    input wire reset_n,
    input wire [CARD_WIDTH - 1 : 0] card_no,
    input wire card_in,
    input wire card_out,
    input wire operation_done,
    input wire [BLNC_WIDTH - 1 : 0] update_balance,
    output reg [PASS_WIDTH - 1 : 0] password,
    output reg [BLNC_WIDTH - 1 : 0] balance,
    output reg pass_flag
);

// mimicing database
reg [PASS_WIDTH - 1 : 0] passwords_database [USERS_NUMS];
reg [PASS_WIDTH - 1 : 0] balances_database [USERS_NUMS];


always @(posedge clk or negedge reset_n) begin
    if(!reset_n) begin
        pass_flag <= 1'b0;
    end
    else if (card_no < USERS_NUMS) begin
        pass_flag <= card_in;
    end
    else begin
        pass_flag <= pass_flag;
    end

end

always @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
        password <= 0;
        balance  <= 0;

        // putting different amounts of balance
        balances_database[0]  = 'd2200  ;
        balances_database[1]  = 'd50000 ;
        balances_database[2]  = 'd10000 ;
        balances_database[3]  = 'd200000;
        balances_database[4]  = 'd100000;
        balances_database[5]  = 'd0     ;
        balances_database[6]  = 'd20000 ;
        balances_database[7]  = 'd25000 ;
        balances_database[8]  = 'd40000 ;
        balances_database[9]  = 'd1     ;

        // putting different 4 digit [0 - 9] passwords
        passwords_database[0] = 'b0011_0011_0111_0000;
        passwords_database[1] = 'b0011_0101_0000_0110;
        passwords_database[2] = 'b0100_0000_0111_0110;
        passwords_database[3] = 'b0001_0000_0001_0000;
        passwords_database[4] = 'b0101_0010_1001_1000;
        passwords_database[5] = 'b0110_0110_0011_1001;
        passwords_database[6] = 'b0010_0010_1000_0100;
        passwords_database[7] = 'b1001_0001_0010_0101;
        passwords_database[8] = 'b1000_0110_0101_0111;
        passwords_database[9] = 'b0101_0111_1001_0001;

    end
    else begin
        if (card_in == 1) begin
            if (card_no < USERS_NUMS) begin
                password <= passwords_database[card_no];
                balance <= balances_database[card_no];
            end
            else begin
                password <= 'b0;
                balance  <= 'b0;
            end
        end
        
        if (operation_done || card_out) begin // this sequence is logical
                balances_database[card_no] <= update_balance;
        end
    end
end

endmodule