const bookModel = require('../models/book')

const getAllBooks = async (req, res) => {
    try{
        const books = await bookModel.find({});
        res.status(200).json({books});
    }catch(error){
        res.status(500).json({msg:error});

    }
}

const createBook = async (req,res) => {
    try {
      console.log(req.body)
      const book = await bookModel.create(req.body);
      res.status(201).json({book});
    } catch (error) {
      res.status(500).json({msg:error});
    }
    
  }

module.exports = {getAllBooks, createBook};