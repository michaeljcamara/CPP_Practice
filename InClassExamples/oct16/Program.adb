-- Bob Roos
-- Demonstration of subrange types in Ada.
--
-- To run this program, go to:
--        https://ideone.com
--
-- WARNING: THE ideone SOFTWARE IS PRETTY TEMPERAMENTAL!
--
-- At the bottom of the screen, select "Ada" as the language
-- Paste this program into the window (overwrite any sample code that
-- appears there).
--
-- Click the "stdin" tab and type in the program input, e.g.,
-- 10 14 2015 [be sure to hit "newline" at the end]
-- Click the "run" button.

-- To modify the input, click the "edit" button and enter a new
-- value for input.

-- The following lines include some standard Ada input/output libraries:
With Ada.Text_IO; Use Ada.Text_IO;  
With Ada.Integer_Text_IO; Use Ada.Integer_Text_IO;

procedure Program is
  subtype Month is Integer range 1..12;  -- only allows values in this range
  subtype Day is Integer range 1..31;
  subtype Year is Integer range 1000..2050;
  m: Month;
  d: Day;
  y: Year;
begin
  put("enter month: ");
  get(m); -- will produce runtime error if m < 1 or m > 12
  put("enter day: ");
  get(d); -- will produce runtime error if d < 1 or d > 31

-- Try adding a line that says "d := m" or "m := d"

  put("enter year: ");
  get(y); -- will produce runtime error if y < 1000 or y > 2050
  put(m);
  put("/");
  put(d);
  put("/");
  put(y);
end Program;
