
-- 1. Write query to gett the discontinued Product list (ProductID and name)
USE northwind;
SELECT product_code, product_name FROM products;

-- 2. Retrieve the top 4 cheapest products 
SELECT product_name FROM products ORDER BY list_price ASC LIMIT 4;

-- 3.Write a query to get Product list (id, name, list_price) whose list_price cost between 
-- $15 and $25. Hint: using BETWEEN operator or comparison operators (<>) 
-- combined with AND operator. 
SELECT product_code, product_name, list_price FROM products WHERE list_price BETWEEN 15 AND 25;

-- 4. List employees with two columns: id, full_name which is constructed from 
-- first_name and last_name. 
SELECT id, CONCAT(first_name, " ", last_name) FROM employees;

-- 5. Find employees whose names start with ‘A’. 
SELECT * FROM employees WHERE first_name LIKE 'A%';

-- 6. Show how many different cities the employees living in. 
SELECT DISTINCT COUNT(city) FROM employees;

-- 7. Show ship_name of table orders without duplicated values. 
SELECT DISTINCT ship_name FROM orders;

-- 8. Show the minimum, maximum of list price in Products table 
SELECT MIN(list_price) FROM products;
SELECT MAX(list_price) FROM products;

-- 9. Display the number of current (mean Discontinued = 0) products. 
SELECT COUNT(*) FROM products WHERE discontinued = 0;

-- 10. Show the average and standard deviation of the list_price of products. 
SELECT AVG(list_price) FROM products;
SELECT STDDEV(list_price) FROM products;

-- 11. Use subquey, show Product list (name, list_price) expensive than the average price. 
SELECT product_name, list_price FROM products WHERE list_price > (SELECT AVG(list_price) FROM products);

-- 12. Insert a new row to table Suppliers with the following values: company = ‘Habeco’, 
-- last_name = ‘Nguyễn’, first_name = ‘Hồng Linh’ city = ‘Hanoi’, country_region = 
-- ‘Vietnam’
INSERT INTO suppliers (company, last_name, first_name, city, country_region)
VALUES('Habeco', 'Nguyễn', 'Hồng Linh', 'Hanoi', 'Vietnam');

-- 13. Insert a new product into table products with the following values: product_code = 
-- ‘TBTruc Bach’, SupplierID = the value corresponding to ‘Habeco’, list_price = 22, 
-- discontinued = 0, category = ‘Beverages’ 
INSERT INTO products(product_code, supplier_ids, list_price, discontinued, category)
VALUES('TBTruc Bach', (SELECT id FROM suppliers WHERE company = 'Habeco'), 22, 0, 'Beverages');

-- 14. Modify the information of ‘Truc Bach’: standard_cost = 18. 
UPDATE products
SET standard_cost = 18
WHERE product_code = 'TBTruc Bach';

-- 15. Try deleting the row which is just inserted in table Suppliers.
DELETE FROM suppliers WHERE company = 'Habeco';