-- Write your PostgreSQL query statement below
Select max(salary) AS SecondHighestSalary
from Employee
Where salary<(
    Select max(salary)
    from Employee
);