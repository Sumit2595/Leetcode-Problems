# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
delete s from Person as s , Person as t where s.id > t.id and s.email = t.email;
