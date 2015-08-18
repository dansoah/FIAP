DEFINE p_num = 5
DECLARE
  v_num NUMBER(3) := &&p_num;
  v_sal employees.salary%type := 0;
  CURSOR v_emp_cursor IS
    SELECT DISTINCT salary FROM employees ORDER BY salary DESC;
BEGIN

  open v_emp_cursor;
  FETCH v_emp_cursor INTO v_sal;
  WHILE v_emp_cursor%ROWCOUNT <= v_num AND v_emp_cursor%FOUND loop
    INSERT INTO top_salaries VALUES (v_sal);
    FETCH v_emp_cursor INTO v_sal;
  END LOOP;
  CLOSE v_emp_cursor;

END;
