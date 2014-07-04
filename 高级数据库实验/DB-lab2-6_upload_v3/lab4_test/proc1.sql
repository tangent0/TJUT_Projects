declare
     my_part_number		part.part_number%TYPE;
     status		char(1);

/* Declare the local procedure mod_status*/
     procedure mod_status (num number) is
     	begin
     		update part2 set status='A' where part_number = num;
     	end; 

begin
    my_part_number := 101;		-- initialize part_number of part2
    mod_status (my_part_number);
    commit;
end;
/
