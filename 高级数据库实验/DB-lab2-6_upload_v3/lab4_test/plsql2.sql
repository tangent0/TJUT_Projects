declare
     cursor c1 is
        select part_number, part_name, qty_stock, qty_ordered, qty_minimum 
	from part 
	where qty_minimum  <= (qty_stock + qty_ordered)
        order by part_number asc;   	-- ascending order on part_number
        
     my_part_number	part.part_number%TYPE;
     my_part_name 	part.part_name%TYPE;
     my_qty_stock	part.qty_stock%TYPE;
     my_qty_ordered	part.qty_ordered%TYPE;
     my_qty_minimum 	part.qty_minimum%TYPE;
     status		char(1) := 'I';

begin
    delete from part2;		-- initialize the table part2
    
    -- open the cursor c1, execute the select and set the pointer on the first row of the result
    open c1;			

    loop
        fetch c1 into my_part_number, my_part_name, my_qty_stock, my_qty_ordered, my_qty_minimum;
        exit when c1%notfound;   	/* exit from loop if no more row
					to process in the result of select */
        insert into part2 values (my_part_number, my_part_name, status);
        commit;
    end loop;

    close c1;		-- close cursor
end;
/
