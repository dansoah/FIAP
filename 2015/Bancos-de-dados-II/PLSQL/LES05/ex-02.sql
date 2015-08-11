-- EX 5.2

set verify off;

--Script
DROP TABLE EMP;
CREATE TABLE EMP AS SELECT * FROM EMPLOYEES;

ALTER TABLE EMP ADD STARS VARCHAR(50);

--exercicio
DEFINE p_empno = 176 -- É definido como varchar
DECLARE
  --Fazendo a referência com a variável global e trocando varchar por number
  v_empno emp.employee_id%type := TO_NUMBER(&p_empno); 
  v_asterisk emp.stars%type := NULL;
  v_salary emp.salary%type := 0;
BEGIN

  SELECT
    NVL(CEIL(SALARY / 1000),0)
  INTO v_salary
  FROM EMP
  WHERE employee_id = v_empno AND salary >= 1000;

  FOR i IN 1.. v_salary LOOP
    v_asterisk := v_asterisk || '*';
  END LOOP;
  
  UPDATE EMP SET stars = v_asterisk WHERE employee_id = p_empno;
  COMMIT;
END;
