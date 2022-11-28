USE northwind;

-- 1. List all orders made after 2006-03-24
SELECT * FROM orders WHERE order_date > '2006-03-24';


-- 2. Show product_code, unit_price, quantity, value of orders details whose order_id = 31
SELECT product_id, unit_price, quantity, (unit_price * quantity * (1-discount)) AS value FROM order_details WHERE order_id = 31;


-- 3. A query to show the order_id, order_date, the company name of customer, value of each row for orders made after ‘2006-03-24
SELECT DISTINCT order_details.order_id, order_date, customers.company, (order_details.unit_price * order_details.quantity * (1-order_details.discount)) AS value
FROM ((orders
	INNER JOIN order_details ON orders.id = order_details.order_id)
	INNER JOIN customers ON orders.customer_id = customers.id)
WHERE orders.order_date > '2006-03-24';


-- 4. Write a query to show information of each order including: order id, order_date, 
-- company name, sub_total value of orders made after ‘2006-03-24’	
SELECT DISTINCT 
	order_details.order_id, 
    order_date, 
    customers.company, 
    SUM(order_details.unit_price * order_details.quantity * (1-order_details.discount)) AS sub_total
FROM ((orders
	INNER JOIN order_details ON orders.id = order_details.order_id)
	INNER JOIN customers ON orders.customer_id = customers.id)
WHERE orders.order_date > '2006-03-24' GROUP BY order_details.order_id;

-- 5. Write a query to show information of each order including: order id, order_date, 
-- company name, sub_total of orders made after ‘2006-03-24’ and sub_total greater than 
-- or equal to 800.
SELECT DISTINCT order_details.order_id, order_date, customers.company, SUM(order_details.unit_price * order_details.quantity * (1-order_details.discount)) AS sub_total
FROM ((orders
	INNER JOIN order_details ON orders.id = order_details.order_id)
	INNER JOIN customers ON orders.customer_id = customers.id)
WHERE orders.order_date > '2006-03-24' GROUP BY order_details.order_id HAVING sub_total >= 800;

-- 6. As the company will give rewards for employees who sold more than 1000$, the 
-- director needs a report listing these employees (full_name, sale in dolars) from high to 
-- low. Write a query for this report. 
SELECT DISTINCT 
	CONCAT(first_name, " ", last_name) AS full_name, SUM(order_details.unit_price * order_details.quantity * (1-order_details.discount)) AS sale_by_dollar
FROM ((employees INNER JOIN orders ON employees.id = orders.employee_id) INNER JOIN order_details ON orders.id = order_details.order_id)
HAVING sale_by_dollar > 1000;

-- 7. Create a view consisting all partners (customers and suppliers) of Northwind. The 
-- columns consist of company, full_name, email_address, and type (C for customers, S 
-- for suppliers)
SELECT customers.company, CONCAT(customers.first_name, customers.last_name) AS full_name, customers.email_address, "C" AS type
FROM customers
UNION
SELECT suppliers.company, CONCAT(suppliers.first_name, suppliers.last_name) AS full_name, suppliers.email_address, "S" AS type
FROM suppliers;

-- 8. Show all categories, eliminate duplicated rows, and sort the results according to 
-- alphabet order.
SELECT DISTINCT category FROM products
ORDER BY category ASC;

-- 9.Show minimum, maximum, average, standard deviation, and variance of standard_cost
-- of products
SELECT MIN(standard_cost) AS MinimumCost, MAX(standard_cost) AS MaximumCost, STDDEV(standard_cost) AS StandardDeviation, VARIANCE(standard_cost) AS Variance FROM products;

-- 10. Show the average list_price of each category.
SELECT AVG(list_price) FROM products
WHERE category IN (SELECT *);

-- 11. Create a stored procedure listing top n categories whose average prices are highest. The 
-- procedure should accept n as a parameter.
-- 12. Among avarage list_prices of categories above, show the minimum values
DELIMITER //
CREATE PROCEDURE top_n_avg_caterogy (IN Top INTEGER)
BEGIN
	SELECT AVG(list_price) AS avg_price, MIN(list_price) AS avg_price FROM products
    WHERE category IN (SELECT *)
    ORDER BY avg_price ASC
    LIMIT Top;
END //
DELIMITER ;

-- 13. For each purchase_order, show their id, full_name of person creating, and full_name 
-- of person approving
SELECT employees.id AS ID, CONCAT(employees.first_name, " ", employees.last_name) AS full_name, "Create the order" AS TYPE
FROM (employees INNER JOIN purchase_orders ON purchase_orders.created_by = employees.id)
UNION
SELECT employees.id AS ID, CONCAT(employees.first_name, " ", employees.last_name) AS full_name, "Approve the order" AS TYPE
FROM (employees INNER JOIN purchase_orders ON purchase_orders.approved_by = employees.id);
