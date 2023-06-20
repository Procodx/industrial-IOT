"""empty message

Revision ID: 6998c39941df
Revises: dcd86d91a9dd
Create Date: 2023-06-20 12:04:33.929486

"""
from alembic import op
import sqlalchemy as sa


# revision identifiers, used by Alembic.
revision = '6998c39941df'
down_revision = 'dcd86d91a9dd'
branch_labels = None
depends_on = None


def upgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    with op.batch_alter_table('users', schema=None) as batch_op:
        batch_op.alter_column('token',
               existing_type=sa.VARCHAR(length=300),
               type_=sa.String(length=5000),
               existing_nullable=True)

    # ### end Alembic commands ###


def downgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    with op.batch_alter_table('users', schema=None) as batch_op:
        batch_op.alter_column('token',
               existing_type=sa.String(length=5000),
               type_=sa.VARCHAR(length=300),
               existing_nullable=True)

    # ### end Alembic commands ###
