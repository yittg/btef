from setuptools import setup, Extension


def readme():
    with open("README.rst", 'r') as rf:
        return rf.read()

setup(
    name='btef',
    author='Yi Tang',
    author_email='ssnailtang@gmail.com',
    version='0.1',
    description='c extend for file object',
    long_description=readme(),
    url='https://github.com/yittg/btef',
    license='MIT',
    ext_modules=[
        Extension('btef', sources=['src/btefmodule.c']),
    ])
