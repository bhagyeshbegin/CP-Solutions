-- Write your PostgreSQL query statement below
Select firstName,lastName,city,state
from Person
Left OUTER JOIN Address
ON Person.personID = Address.personID;