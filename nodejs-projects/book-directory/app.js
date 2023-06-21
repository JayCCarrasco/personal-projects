//Import express
const express = require('express');
const app = express();  //Instance for express.
const novelRouter = require('./routes/novel');
const connectDB = require('./db/connect');
require('dotenv').config();

//moddleware
app.use(express.json());

//const theatreRouter = require('./routes/theatre');
app.use('/api/books/novel', novelRouter);
//app.use('/api/books/theatre', theatreRouter);

//getting req, res in main directory /
app.get(('/'), (req, res) => {
    res.statusCode = 200;
    res.end('Book app');
})

//Defining port and passing it in listen method
//callback function returning console.log
const PORT = 3000;

const start = async () => {
    try {
        await connectDB(process.env.MONGO_URI);
        app.listen(PORT, console.log(`server listening in port ${PORT}`));
    } catch (error) {
        console.log(error);
    }
}

start();
