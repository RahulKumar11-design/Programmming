select c.customer_name, sum(p.quantity*p.price) as total_spending, count(distinct p.product_name) as no_of_products
from customers c
join orders o on c.customer_id = o.customer_id
join order_items p on o.order_id = p.order_id
where c.city = "New York"
group by c.customer_id,c.customer_name
having sum(p.quantity)>1


#mistake => duplicate addition if total_spending = o.total_amount

select e.empid, e.empname, d.deptname, s.basic
from employee_info e
join dept_info d
on e.depto = d.deptid
join salary_info s
on e.employee_category = s.employee_category
where d.deptname = 'IT';

