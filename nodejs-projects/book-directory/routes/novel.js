//import express and novels
const express = require('express');
const {novel} = require('../data/books').infoBooks;

//create router
const novelRouter = express.Router();

//middleware
novelRouter.use(express.json());

//get and exports
novelRouter.get(('/'), (req, res) => {
    res.send(novel);
})

module.exports = novelRouter;