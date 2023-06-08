//Import express
const express = require('express');
const app = express();  //Instance for express

//Routers import and use
const novelRouter = require('./routes/novel');
const theatreRouter = require('./routes/theatre');
app.use('/api/books/novel', novelRouter);
app.use('/api/books/theatre', theatreRouter);

//getting req, res in main directory /
app.get(('/'), (req, res) => {
    res.statusCode = 200;
    res.end('Book app');
})

//Defining port and passing it in listen method
//callback function returning console.log
const PORT = 3000;

app.listen(PORT, () => {
    console.log(`server listening in port ${PORT}`);
})