-- DESCRIBE USER_CONSTRAINTS;
-- DESCRIBE USER_CONS_COLUMNS;

SELECT 
    UCC.COLUMN_NAME, 
    UCC.CONSTRAINT_NAME,
    UC.CONSTRAINT_TYPE,
    UC.SEARCH_CONDITION,
    UC.STATUS
FROM 
    USER_CONS_COLUMNS UCC
INNER JOIN USER_CONSTRAINTS UC ON UPPER(UC.CONSTRAINT_NAME) = UPPER(UCC.CONSTRAINT_NAME)
WHERE UCC.TABLE_NAME = '&TABLE'
