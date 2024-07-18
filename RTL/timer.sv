module timer #(
    parameter width = 32
)(
    input wire clk,
    input wire reset_n,
    input wire start,
    input wire restart,
    input wire [width - 1 : 0] threshold,
    output reg time_out
);

reg [width - 1 : 0] counter;

always @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
        counter <= 'b0;
        time_out <= 1'b0;
    end
    else if (start) begin
        if (!restart) begin
            counter <= counter + 'b1;
        end
        else begin
            counter <= 'b0;
        end

        if (counter == threshold) begin
            time_out <= 1'b1;
            counter <= 'b0;
        end
        else begin
            time_out <= 1'b0;
        end
    end
    else begin
        counter <= 'b0;
    end
end

endmodule