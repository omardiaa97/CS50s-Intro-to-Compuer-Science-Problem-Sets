select distinct name from people join stars on people.id = stars.person_id join movies on stars.movie_id = movies.id where people.name != 'Kevin Bacon' and movies.id in (select distinct movies.id from movies join stars on movies.id = stars.movie_id join people on stars.person_id = people.id where people.name = 'Kevin Bacon' and people.birth = 1958);
